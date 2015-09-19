<?php

/*

  ____          _          _   _             ____      _
 / ___|___   __| | ___  __| | | |__  _   _  |  _ \ ___| |__   ___  ___ __ _
| |   / _ \ / _` |/ _ \/ _` | | '_ \| | | | | |_) / _ \ '_ \ / _ \/ __/ _` |
| |__| (_) | (_| |  __/ (_| | | |_) | |_| | |  _ <  __/ |_) |  __/ (_| (_| |
 \____\___/ \__,_|\___|\__,_| |_.__/ \__, | |_| \_\___|_.__/ \___|\___\__,_|
                                      |___/


                (╯°□°）╯︵ ┻━┻   ┻━┻︵ \(°□°)/ ︵ ┻━┻           ¯\_(ツ)_/¯

*/

    //configuration
    require("../includes/config.php");


    //if user reached page via GET(as by clicking a link or via redirect)
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
       render("register_form.php", ["title" => "Register"]);
    }

    //else if user reacher page via post (as by submitting a form via POST)
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //validate submission
        if(empty($_POST["username"]))
        {
            apologize("You must provide your username");
        }

        else if(empty($_POST["password"]))
        {
            apologize("You must provide your password");
        }

        else if($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your password and confirmation do not match");
        }

        //query database for user
        query("INSERT INTO users (username, hash) VALUES(?, ?)", $_POST["username"], crypt($_POST["password"]));

        //if error occurred, username alreay exists
        if($result === false)
        {
            apologize("That username is already taken");
        }

        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];

        //store id in session
        $_SESSION["id"] = $rows[0]["id"];


        // redirect to homepage
        redirect("index.php");
    }

?>
