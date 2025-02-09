create table if not exists track (
	id serial primary key,
	name varchar(50),
	duration integer not null,
	album_id integer not null,
	collection_id integer not null
);

create table if not exists author (
	id serial primary key,
	name varchar(100)
);

create table if not exists album (
	id serial primary key,
	name varchar(80),
	edition_year integer not null,
	author_id integer not null references author(id)
);

create table if not exists Style (
	id serial primary key,
	name varchar(50)
);

create table if not exists author_style (
	author_id integer references author(id),
	style_id integer references style(id)
);

create table if not exists collection (
	id serial primary key,
	name varchar(80),
	edition_year integer not null
	);

create table if not exists track_album (
	album_id integer not null,
	track_id integer not null,
	foreign key (album_id) references album(id),
	foreign key (track_id) references track(id),
	constraint pk primary key (album_id, track_id)
	);

create table if not exists track_collection (
	collection_id integer not null,
	track_id integer not null,
	foreign key (collection_id) references collection(id),
	foreign key (track_id) references track(id),
	constraint collection_pk primary key (collection_id, track_id)
	);
