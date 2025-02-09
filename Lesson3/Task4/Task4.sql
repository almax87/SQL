SELECT a.name 
FROM album a
LEFT JOIN author_style as2 ON as2.author_id = a.author_id
LEFT JOIN style s ON s.id = as2.style_id 
GROUP BY a.name
HAVING COUNT(DISTINCT s.name) > 1
ORDER BY a.name;

SELECT t.name FROM track t
WHERE NOT EXISTS
(SELECT FROM track_collection tc  WHERE tc.track_id = t.id);

SELECT au.name FROM author au
LEFT JOIN album al ON al.author_id = au.id
LEFT JOIN track_album ta ON al.id = ta.album_id
LEFT JOIN track t ON t.id = ta.track_id
GROUP BY au.name, t.duration, t.name
HAVING t.duration = (SELECT MIN(duration) FROM track)
ORDER BY au.name;

SELECT a.name FROM album a
JOIN track_album ta ON a.id = ta.album_id
GROUP BY a.name
HAVING COUNT(ta.track_id) = (SELECT MIN(track_count) FROM (SELECT COUNT(track_id) as track_count FROM track_album ta GROUP BY ta.album_id) as subquery)
ORDER BY a.name;
