<table class="table table-stripend">
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    <?php foreach($positions as $position): ?>
        <tr>
            <td class="text-left"><?=$position["transaction"] ?></td>
            <td class ="text-left"><?=$position["date/time"] ?></td>
            <td class ="text-left"><?=$position["symbol"] ?></td>
            <td class ="text-left"><?=$position["shares"] ?></td>
            <td class ="text-left"><?=$position["price"] ?></td>
        </tr>
        
    <?php endforeach ?>
</table>
<div>
    <a href="index.php">Go to Portfolio</a>
</div>
