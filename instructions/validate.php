<?php
if (isset($_POST['answer'])) {
	if ($_POST['answer'] == "ANSWER") { ?>
		<!DOCTYPE html>
		<html>
		<head>
			<title>Los Altos Hacks | Capture The Flag</title>
			<link rel="stylesheet" href="css/main.css" />
		</head>
		<body>
			<div class="main">
				<h4>$ Los Altos Hacks<br /><span style="color: tomato">CTF</span></h4>
			</div>
			<p>$ Your hash was correct!</p>
			<p>Please go to {{{ ROOM }}} to see if you were first! If you were, you get some sweet prizes. :)</p>
		</body>
		</html>
	<?php } else { ?>
		<!DOCTYPE html>
		<html>
		<head>
			<title>Los Altos Hacks | Capture The Flag</title>
			<link rel="stylesheet" href="css/main.css" />
		</head>
		<body>
			<div class="main">
				<h4>$ Los Altos Hacks<br /><span style="color: tomato">CTF</span></h4>
			</div>
			<p style="color: tomato">$ Your hash was incorrect!</p>
			<p><a href="." class="back">Click here to go back.</a></p>
		</body>
		</html>
<?php } } else { header("Location: ."); } ?>