    <form class="form-inline" action="search.php" method="post">
            <fieldset>
                <div class="form-group">
                    <select class="form-control" name="agency"> 
                        <option value></option>
                        <?php foreach($positions as $position): ?>
                        <option><?=$position["agency"]?></option>
                        <?php endforeach ?>
                   </select>
                </div>
                <div class="form-group">
                    <button type="submit" class="btn btn-info">Search</button>
                </div>
            </fieldset>
     </form>


