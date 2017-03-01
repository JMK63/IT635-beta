DROP TABLE if exists users;
create table users (
	id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	username VARCHAR(16),
	password varchar(255),
	permissions varchar(255)
);
