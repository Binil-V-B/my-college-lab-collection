declare
a number;
b number;
sum number;
begin
a:=&a;
b:=&b;
sum:=a+b;
dbms_output.put_line('sum= '||sum);
end;
/