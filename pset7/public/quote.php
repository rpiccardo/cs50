<?php

    // configuration
    require("../includes/config.php");
    
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {

        // render quote
        render("quote_form.php", ["title" => "Get Quote"]);
        
    }
    
     // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
        $stock = lookup($_POST["symbol"]);
        
        
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a valid symbol");
        }
       
        //check that the symbol is valid
        else if($stock === false)
        {
            apologize("You must provide a valid symbol");
        }
        
        render("display.php", ["stock" => $stock]);
        
    }

?>
