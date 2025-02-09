SELECT t.name, t.duration 
	FROM track t
	WHERE t.duration = (SELECT MAX(duration) FROM track);

SELECT t.name
	FROM track t
	WHERE t.duration > 3.5;

SELECT c.name
	FROM collection c
	WHERE (c.edition_year >= 2018) AND (c.edition_year < 2021)
	
SELECT a.name
	FROM author a
	WHERE array_length(string_to_array(trim(a.name),' '), 1) = 1;

SELECT t.name
	FROM track t
	WHERE t.name ILIKE '%my%';
