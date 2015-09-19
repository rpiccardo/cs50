<?php 

    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //validate stock exists
        $stock = lookup($_POST["symbol"]);
        
        //validate submission
        if(empty($_POST["symbol"]))
        {
            apologize("You must specify a stock to buy.");
        }
     
        if(empty($_POST["shares"]))
        {
            apologize("You must specify a number of shares.");
        }
        
        //check that the symbol is valid
        else if($stock === false)
        {
            apologize("You must provide a valid symbol");
        } 
        
        //validate number of shares
        if(preg_match("/^\d+$/", $_POST["shares"]) == 0)
        {
            apologize("You must enter a valid number of shares");
        } 
        
        //calculate cost of stock being bought
        $cost = $_POST["shares"] * $stock["price"]; 
        
        //get how much cash the user has
        $array = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        $cash = $array[0];
        
        //make sure user can afford the stock
        if($cash["cash"] < $cost)
        {
            apologize("You don't have enough cash.");
        }
        
        $symbol = strtoupper($_POST["symbol"]);
        
        //insert new row for new stock, or update number of shares if user already owns stock
        $new_stock = query("INSERT INTO portfolio(id, symbol, shares) VALUES ( ?, ?, ?) ON DUPLICATE KEY UPDATE shares = 
                            shares + VALUES(shares)", $_SESSION["id"], $symbol, $_POST["shares"]);
        
        //update cash
        $balance = query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
        
        $buy = 'BUY';
         
         //update purchase history
        $purchase = query("INSERT INTO history(id, transaction, symbol, shares, price) 
                            VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $buy, $symbol, 
                            $_POST["shares"], $stock["price"]);
        
        // redirect to portfolio
        redirect("/");
        
    }
?>
