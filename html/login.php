<?php


if (!isset($_POST))
{
	$msg = "NO POST MESSAGE SET";
	echo json_encode($msg);
	exit(0);
}
$request = $_POST;
$response = "unsupported request type";
switch ($request["type"])
{
	case "login":
		$response = "login, yes";
	break;
}
echo json_encode($response);
exit(0);

?>
