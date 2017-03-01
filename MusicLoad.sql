LOAD DATA LOCAL INFILE '/home/jmk/MusicLib/data.csv' 
INTO TABLE music  
    FIELDS TERMINATED BY ', ' 
           OPTIONALLY ENCLOSED BY '"'
    LINES  TERMINATED BY '\n' -- or \r\n
(id, title, artist, album, track, year);
