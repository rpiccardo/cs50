<ul class="nav nav-pills">
    <li>
        <a href="quote.php"><b>Quote</b></a>
    </li>
    <li>
        <a href="buy.php"><b>Buy</b></a>
    </li>
    <li>
        <a href="sell.php"><b>Sell</b></a>
    </li>
    <li>    
        <a href="history.php"><b>History</b></a>
    </li>
    <li>
        <a href="password_change.php"><b>Change Password</b></a>
    </li>
</ul>

<table class="table table-stripend">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>
    <?php foreach($positions as $position): ?>
        <tr>
            <td class="text-left"><?=$position["symbol"] ?></td>
            <td class ="text-left"><?=$position["name"] ?></td>
            <td class ="text-left"><?=$position["shares"] ?></td>
            <td class ="text-left"><?=$position["price"] ?></td>
            <td class ="text-left"><?=$position["total"] ?></td>
        </tr>
        
    <?php endforeach ?>
    <tr>
        <td colspan = 4 class ="text-left">CASH</td>
        <td class ="text-left"><?= number_format($cash["cash"], 2); ?></td>
    </tr>
</table>

<div>
    <a href="logout.php">Log Out</a>
</div>


