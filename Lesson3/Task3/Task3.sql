SELECT as2.style_id, COUNT(*)
	FROM author_style as2
	GROUP BY as2.style_id;

SELECT count(t.id), a.name
	FROM track t
	JOIN album a ON a.id = t.album_id
	WHERE  a.edition_year BETWEEN 2019 AND 2020
	GROUP BY a.name;

SELECT avg(t.duration), a.name
	FROM track t
	JOIN album a ON a.id = t.album_id
	GROUP BY a.name;

SELECT DISTINCT a2.name
	FROM author a2
	WHERE a2.name NOT IN (
    SELECT DISTINCT a2.name
    FROM author a2
    JOIN album a ON a.author_id = a2.id
    WHERE a.edition_year = 2020
);

SELECT c.name FROM collection c
LEFT JOIN track t ON t.collection_id = c.id 
LEFT JOIN album a ON t.album_id = a.id
LEFT JOIN author a2 ON a.author_id = a2.id
WHERE a2.id = 3
GROUP BY c.name


