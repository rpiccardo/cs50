<?php

    //configuration
    require("../includes/config.php");
    
    //if user reached page via GET(as by clicking a link or via redirect)
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("password_change_form.php", ["title" => "Change Password"]);
    }
    
    //else if user reaches page via post (as by submitting a form via POST)
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if(empty($_POST["old_password"]))
        {
            apologize("You must provide current password.");
        }
        
        // query database for user
        $rows = query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        
        foreach($rows as $row)
        {
            // first (and only) row
            $row = $rows[0];
            
            //compare hash of user's input against hash that's in database
            if (crypt($_POST["old_password"], $row["hash"]) != $row["hash"])
            {
               apologize("Invalid password.");
            }
        }
        
        if($_POST["old_password"] == $_POST["new_password"])
        {
            apologize("Your new password cannot be the same as current password.");
        }
        
        else if($_POST["new_password"] != $_POST["confirmation"])
        {
            apologize("Your new password and confirmation do not match");
        }
        
        //query to update new password in users table 
        $password = query("UPDATE users SET hash = ? WHERE id = ?",crypt($_POST["new_password"]), $_SESSION["id"]);
       
        // redirect to display
        render("change_display.php");
    
    }    
?>
