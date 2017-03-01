<?php

class Access
{
private $db;

public function __construct($database)
{
	$this->db = new mysqli("localhost","root","2953792",$database);
	if ($this->db->connect_errno != 0)
	{
		echo "error connecting to databse: ".$this->db->connect_error.PHP_EOL;
		exit();
	}
}

public function __destruct()
{
	if (isset($this->db))
	{
		$this->db->close();
	}
}

public function getMusicRecords()
{
	$query = "select * from music;";

	$queryResponse = $this->db->query($query);
	$response = array();
	while($row = $queryResponse->fetch_assoc())
	{
		$response[] = $row;
	}
	return $response;
}

public function addMusicRecord($id,$title,$artist,$album,$track,$year)
{
	$id = $this->db->real_escape_string($studentName);
	$title = $this->db->real_escape_string($title);
	$artist = $this->db->real_escape_string($artist);
	$album = $this->db->real_escape_string($album);
	$track = $this->db->real_escape_string($track);
	$year = $this->db->real_escape_string($year);
	echo "before escape:\n\"$year\"\n";
	echo "after escape:\n$year\n";
	$query = "insert into music(id,title,artist,album,track,year) VALUES ('$id','$title','$artist',$album,'$track','$year');";

	echo "executing SQL statement:\n".$query."\n";
	if (!$this->db->query($query))
	{
		echo "failed to insert record for $title".PHP_EOL;
	}
}

public function validateUser($username,$password)
{
	$un = $this->db->real_escape_string($username);
	$pw = $this->db->real_escape_string($password);

	$query = "select * from users where username = '$un';";
	$result = $this->db->query($query);

	while ($row = $result->fetch_assoc())
	{
		if ($row["password"] == $pw)
		{
			// I have a match
			return true;
		}
	}
	return false;
}

}
?>

