<?php
session_start();

$username = $_POST['username'];
$password = $_POST['password'];

$db_username = "capture";
$db_password = "the";
$db_database = "flag";

$connection = mysqli_connect("127.0.0.1", $username, $password, $database) or die("Unable to connect to server!");

$login = mysqli_query($connection, "SELECT `username` FROM `accounts` WHERE `password` = " . $password . ";");
if (!$login) {
	?>
	<!DOCTYPE html>
	<html>
	<head>
		<title>validate</title>
		<link rel="stylesheet" href="css/main.css" />
	</head>
	<body>
		<p>your username and password do not match the database's credentials. database said: "<?php echo $login; ?>" <a href=".">try again</a></p>
	</body>
	</html>
	<?php
} else {
	$_SESSION['logged_in'] = 1;
	header("Location: cp.php");
}
?>