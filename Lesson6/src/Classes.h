#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
class Book;
class Stock;
class Shop;
class Sale;

class Publisher{
    public:
        std::string name = "";
        Wt::Dbo::collection <Wt::Dbo::ptr<Book>> books;

        template <class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, name, "name");
            Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
        }
};

class Book{
    public:
        std::string title = "";
        Wt::Dbo::ptr<Publisher> publisher;
        Wt::Dbo::collection <Wt::Dbo::ptr<Stock>> stocks;
        template <class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, title, "title");
            Wt::Dbo::belongsTo(a, publisher, "publisher");
            Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
        }

};

class Stock{
    public:
        int count{};
        Wt::Dbo::ptr<Shop> shop;
        Wt::Dbo::ptr<Book> book;
        Wt::Dbo::collection <Wt::Dbo::ptr<Sale>> sales;
        
        
        template <class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, count, "count");
            Wt::Dbo::belongsTo(a, shop, "shop");
            Wt::Dbo::belongsTo(a, book, "book");
            Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
        }
};

class Shop{
    public:
        std::string name{""};
        Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

        template <class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, name, "name");
            Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
        }
};

class Sale{
    public:
        double price{};
        std::string date_sale{""};
        int count{};
        Wt::Dbo::ptr<Stock> stock;

        template <class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, price, "price");
            Wt::Dbo::field(a, date_sale, "date_sale");
            Wt::Dbo::field(a, count, "count");
            Wt::Dbo::belongsTo(a, stock, "stock");
        }
};