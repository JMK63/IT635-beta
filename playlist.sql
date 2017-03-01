drop table if exists playlist;

create table playlist(
	id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	title varchar(),
	artist varchar(50),
	album varchar(50),
	track varchar(50),
	year INT(4),
);
