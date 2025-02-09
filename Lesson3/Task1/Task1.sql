INSERT INTO author(name)
	VALUES ('Deep Purple'), ('Scorpions'), ('Prodigy'), ('Nirvana');

INSERT INTO style (name)
	VALUES ('rock'), ('grunge'), ('electro');
	
INSERT INTO album (name, edition_year, author_id)
	VALUES ('Slaves and Masters', 1990, 1), ('Stormbringer', 1974, 1),
			('Crazy World', 1990, 2), ('Face the Heat', 1993, 2),
			('Invaders Must Die', 2020, 3), ('The Fat of the Land', 1997, 3),
			('Nevermind', 1991, 4);

INSERT INTO collection (name, edition_year)
	VALUES ('Collection1', 2019), ('Collection2', 2010), ('Collection3', 2020), ('Collection4', 2022);
	
INSERT INTO track (name, album_id, duration, collection_id)
	VALUES ('King of Dreams', 1, 5, 1), ('Too Much Is Not Enough', 1, 4, 2), ('Soldier of Fortune', 2, 3, 3), ('Holy Man', 2, 4, 1),
			('Wind of Change', 3, 5, 2), ('Send Me an Angel', 3, 4, 3), ('Alien Nation', 4, 6, 1), ('No Pain No Gain', 4, 4, 2),
			('Invaders Must Die', 5, 5, 3), ('Stand Up', 5, 5, 1), ('Diesel Power', 6, 4, 2), ('Firestarter', 6, 5, 3), ('Come as You Are', 7, 3, 1),
			('Polly', 7, 3, 2);

INSERT INTO track_collection (collection_id, track_id)
	SELECT t.collection_id, t.id
	FROM track t;

INSERT INTO track_album (album_id, track_id)
	SELECT t.album_id, t.id
	FROM track t
	ORDER BY album_id;

INSERT INTO author_style (style_id, author_id)
	VALUES (1, 1), (1, 2), (1, 3), (3, 3), (1, 4), (2, 4);
		
INSERT INTO track (name, album_id, duration)
	VALUES ('My Love', 5, 7);

INSERT INTO track_album (album_id, track_id)
	VALUES (5, 17)