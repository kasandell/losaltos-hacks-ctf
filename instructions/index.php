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
	<p>$ Instructions paragraph coming soon... :)</p>
	<div class="container">
		<h3>$ The CTF starts at 22:00 on 02-04-17. Button will activate at this time.</h3>
		<?php 
			date_default_timezone_set('America/Los_Angeles');

			if (strtotime('2/4/2017 22:00') < strtotime('now')) {
				echo '<a href="{{{ LINK HERE }}}" class="go">Begin</a>';
			} else {
				echo '<a class="go disabled">Begin</a>';
			}
		?>
	</div>

	<div class="container">
		<h3>$ Once you have finished, you will receive a hash. Paste it here with your name to redeem your prize. First person to get it wins!</h3>
		<?php 
			date_default_timezone_set('America/Los_Angeles');

			if (strtotime('2/4/2017 22:00') < strtotime('now')) {
				echo '<form method="post" action="validate.php">';
			} else {
				echo '<form method="post" action="nope.php">';
			}
		?>
			<input type="text" placeholder="answer" name="answer" class="inp" />
			<input type="submit" class="go" value="Submit" />
		</form>
	</div>

	<script>
		function refreshAt(hours, minutes, seconds) {
		    var now = new Date();
		    var then = new Date();

		    if(now.getHours() > hours ||
		       (now.getHours() == hours && now.getMinutes() > minutes) ||
		        now.getHours() == hours && now.getMinutes() == minutes && now.getSeconds() >= seconds) {
		        then.setDate(now.getDate() + 1);
		    }
		    then.setHours(hours);
		    then.setMinutes(minutes);
		    then.setSeconds(seconds);

		    var timeout = (then.getTime() - now.getTime());
		    setTimeout(function() { window.location.reload(true); }, timeout);
		}
		refreshAt(22, 0, 0);
	</script>
</body>
</html>