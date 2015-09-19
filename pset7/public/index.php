<?php

    // configuration
    require("../includes/config.php"); 
    
    //query portfolio table to get stock symbol, shares
    $rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
    
    //query users table to get cash
    $balance = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    //positions
    $positions = [];
    
    //iterate over each stock symbol to lookup the name of the stock and its price
    foreach($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        
        if ($stock !== false)
        {
            //find the cash balance
            $total = $row["shares"] * $stock["price"];
            
            //make a new associative array with each field for the table
            $positions[] = [
                "symbol" => $row["symbol"],
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "total" => $total
            ];
        }
    }
    
    $cash = $balance[0];
    
    render("portfolio.php", ["positions" => $positions, "cash" => $cash, "title" => "Portfolio"]);
   
?>
