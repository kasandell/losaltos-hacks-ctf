<?php
session_start();

if (!empty($_SESSION['logged_in'])) {
	// put your encrypted link here fam
} else {
	header("Location: .");
}
?>