<form action="text.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus class="form-control" name="phone" placeholder="phone number" type="text"/>
        </div>
        <div class="form-group">
        <select class="form-control" name="carrier">
                <option value></option>
                <option>AT&T</option>
                <option>Sprint</option>
                <option>T-Mobile</option>
                <option>Verizon</option>       
        </select>
        </div>
        <div class="form-group">
                    <select class="form-control" name="agency"> 
                        <option value></option>
                        <?php foreach($positions as $position): ?>
                        <option><?=$position["agency"]?></option>
                        <?php endforeach ?>
        </select>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-info">Send</button>
        </div>
     </fieldset>
</form>
