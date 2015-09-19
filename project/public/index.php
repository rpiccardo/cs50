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


        $rows = query("SELECT `agency` FROM `pio` WHERE  `county` =  'miami-dade'");

        $positions = [];

        foreach($rows as $row)
        {
            //make a new associative array with each field for the table
            $positions[] = [
                    "agency" => $row["agency"]

                ];
        }


       render("sidebar.php", [ "positions" => $positions, "title" => "Media Contacts"]);


?>
