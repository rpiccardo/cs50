<?php 

    // configuration
    require("../includes/config.php"); 
    
    $rows = query("SELECT * FROM `history` WHERE id = ?", $_SESSION["id"]);
    
    $positions = [];
    
    foreach($rows as $row)
    {
        //make a new associative array with each field for the table
        $positions[] = [
            "transaction" => $row["transaction"],
            "date/time" => $row["date/time"],
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "price" => $row["price"]
        ];
    }
    
    // render form
    render("history_display.php", ["positions" => $positions, "title" => "History"]);
   
    
?>
