declare
num1 number;
num2 number;
begin
num1:=&num1;
num2:=&num2;
if(num1>num2) then
dbms_output.put_line(num1||' is the largest');
else
dbms_output.put_line(num2||' is the largest');
end if;
end;
/