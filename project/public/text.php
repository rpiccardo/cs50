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

require("../includes/config.php");

  // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {

        $rows = query("SELECT `agency` FROM `pio` WHERE  `county` =  'miami-dade'");

        $positions = [];

        foreach($rows as $row)
        {
            //make a new associative array with each field for the table
            $positions[] = [
                    "agency" => $row["agency"]

                ];
        }

       render("text_form.php", [ "positions" => $positions, "title" => "Phone"]);

    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

        if(empty($_POST["phone"]))
        {
            apologize("You must enter a valid number.");
        }

        if(empty($_POST["carrier"]))
        {
            apologize("You must select a phone carrier.");

        }

        if (is_numeric ($_POST["phone"]))
        {

            $phone = $_POST["phone"];

            $carrier = $_POST["carrier"];

            $rows = query("SELECT * FROM `pio` WHERE agency = ?", $_POST["agency"]);

            $items = [];

            foreach($rows as $row)
            {

                    //make a new associative array with each field for the table
                    $items[] = [

                        "agency" => $row["agency"],
                        "name" => $row["full_name"],
                        "contact" =>$row["contact_name"],
                        "phone" => $row["phone"],
                        "alt_phone" => $row["phone_2"],
                        "alt_email" => $row["email_2"],
                        "twitter" => $row["twitter"],
                        "url" => $row["url"]
                    ];

            }

            $subject = $items[0]["agency"];
            $message = $items[0]["phone"];


            text($phone, $carrier, $subject, $message);

    }

}

?>
