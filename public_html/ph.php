<!DOCTYPE html>
<html>
    <body>
        <table border="1">
            <tbody >
                <?php
                $x = $_POST["fname"];
                for($i = 1; $i < $x + 1; $i += 1) {
                    echo "<tr>";
                    for ($j = 1; $j < $x + 1; $j += 1) {
                        $result = $j * $i;
                        echo "<td> $result </td>";
                    }
                    echo "</tr>";
                } 

                ?>
            </tbody>
        </table>
    </body>
</html>