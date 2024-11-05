<?php
    $servername = "localhost";
    $username = "root";
    $password = "123456789";
    $dbname = "sqli";

    $con = mysqli_connect($servername, $username, $password, $dbname);

    if (!$con) {
        die("Connection failed: " . mysqli_connect_error());
    }

    $name = $_POST['name'];
    $pass = $_POST['pass'];

    $sql = "SELECT * FROM users WHERE name = '$name' AND password = '$password'";
    $result = mysqli_query($con, $sql);

    if (mysqli_num_rows($result) > 0) {
        echo "Login successful!";
    } else {
        echo "Invalid login credentials.";
    }

    // Close connection
    mysqli_close($con);
?>
