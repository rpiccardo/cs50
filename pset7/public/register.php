<?php

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
        query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], crypt($_POST["password"]));
        
        //if error occurred, username alreay exists
        if($result === false)
        {
            apologize("That username is already taken");
        }
        
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        
        //store id in session
        $_SESSION["id"] = $rows[0]["id"];
        

        // redirect to portfolio
        redirect("index.php");
        
    }
    
?>
