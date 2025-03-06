#include <iostream>
#include "Classes.h"

int main()
{
    try
    {
        std::string connectionString = 
        "host=localhost "
        "port=5432 "
        "dbname=bookshop "
        "user=postgres "
        "password=Nofagem2211_";

        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));
        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Shop>("shop");
        session.mapClass<Sale>("sale");
        session.createTables();

        Wt::Dbo::Transaction transaction{session};
        std::unique_ptr<Book> book1 {new Book()};
        std::unique_ptr<Publisher> publisher1 {new Publisher()};
        std::unique_ptr<Stock> stocks {new Stock()};
        std::unique_ptr<Stock> stock1 {new Stock()};
        std::unique_ptr<Stock> stock2 {new Stock()};
        std::unique_ptr<Shop> shop1 {new Shop()};
        std::unique_ptr<Sale> sale1 {new Sale()};
        book1->title = "Evgeniy Onegin";
        publisher1->name = "AST";
        stock1->count = 500;
        stock2->count = 1000;
        shop1->name = "shop1";
        sale1->count = 2;
        sale1->price = 500;
        sale1->date_sale = "02.03.2022";

        auto book1Ptr = session.add(std::move(book1));
        auto shop1Ptr = session.add(std::move(shop1));
        auto sale1Ptr = session.add(std::move(sale1));
        auto stock1Ptr = session.add(std::move(stock1));
        auto stock2Ptr = session.add(std::move(stock2));
        auto publisher1Ptr = session.add(std::move(publisher1));
        stock1Ptr.modify()->book = book1Ptr;
        book1Ptr.modify()->publisher = publisher1Ptr;
        stock1Ptr.modify()->shop = shop1Ptr;
        sale1Ptr.modify()->stock = stock1Ptr;
        
        int input{};
        std::cout << "Введите ID издателя: ";
        std::cin >> input;
        typedef Wt::Dbo::collection<Wt::Dbo::ptr<Book>> Books;
        Books books = session.find<Book>().where ("publisher_id = ?").bind("1");
        for(const Wt::Dbo::ptr<Book>& book : books)
        {
            for (const Wt::Dbo::ptr<Stock>& stock : book->stocks)
                std::cout << stock->shop->name << std::endl;
        }
        
        transaction.commit();

    }
    catch(const Wt::Dbo::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    return 0;
}