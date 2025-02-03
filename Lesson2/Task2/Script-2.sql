CREATE TABLE if not exists employee(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    department VARCHAR(100) NOT NULL,
    boss_id INT,
    FOREIGN KEY (boss_id) REFERENCES employee(id)
);