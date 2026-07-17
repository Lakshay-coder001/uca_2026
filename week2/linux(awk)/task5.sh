awk -F ',' '
BEGIN{ total = 0}
$2 == "Engineering" {total += $3*$4}
END{print "Total Engineering Payroll: $"total}' employee.txt