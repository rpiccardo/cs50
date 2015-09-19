<?php 

    // configuration
    require("../includes/config.php"); 
    
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        
         //get all the stock symbols from the user's portfolio
         $symbols = query("SELECT symbol FROM portfolio WHERE id = ?",$_SESSION["id"]);
        
         // render form
         render("sell_form.php", [ "symbols" => $symbols, "title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        //if empty, apologize
        if (empty($_POST["symbol"]))
        {
             apologize("You must select a stock to sell.");
        }
       
        //get all the information from the specific stock the user selected to sell
        $sell_symbol = query("SELECT * FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        foreach($sell_symbol as $sell_symbol)
        {
            //use the symbol from the query to look up the current price of the stock
            $stock = lookup($sell_symbol["symbol"]);
            
            //get total value of stock by multiplying all shaes with the current price
            $total_value = $sell_symbol["shares"] * $stock["price"];

        }
            
        //delete the stock being sold from the user's portfolio
        $delete_stock = query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);

        //update the new cash balance by adding the total value of the stock share sold
        $new_balance = query("UPDATE users SET cash = cash + ? WHERE id = ?", $total_value, $_SESSION["id"]);
        
        $sell = 'SELL';
        
        //update purchase history
        $sale = query("INSERT INTO history(id, transaction, symbol, shares, price) 
                            VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $sell, $stock["symbol"], 
                            $sell_symbol["shares"], $stock["price"]);
    
        // redirect to portfolio
        redirect("/");
        
    }
    
?>
