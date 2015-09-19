 <ul class="nav nav-pills">
    <li>
        <a href="index.php"><b>Search</b></a>
    </li>
    <li>
        <a href="text.php"><b>Send information to your phone</b></a>
    </li>
    <li>
        <a href="logout.php"><b>logout</b></a>
    </li>

</ul>

       <?php foreach($items as $item): ?>
                 <h3 class="text-left"><?=$item["agency"] ?> <small><?=$item["name"] ?></small></h3>
                 <?php endforeach ?>

 <table class="table table-hover">

             <thead>
                <tr>
                   <th>Contact</th>
                   <th>Phone</th>
                   <th>Email</th>
                   <th>Twitter</th>
                   <th>Website</th>
                 </tr>
             </thead>
                <?php foreach($items as $item): ?>


                 <tr>
                    <td class="text-left"><?=$item["contact"] ?></td>
                    <td class ="text-left"><?=$item["phone"] ?></td>
                    <td class ="text-left"><?=$item["email"] ?></td>
                    <td class ="text-left"><?=$item["twitter"] ?></td>
                    <td class ="text-left"><?=$item["url"] ?></td>

                 <?php endforeach ?>
            </tr>
  </table>
