-- not complete !!!!!
declare
a number;
b number;
c number;
begin
a:=&a;
b:=&b;
c:=&c;
if(a>b) then
    if(a>c) then
        dbms_output.put_line(a||' is the greatest');
    else
        dbms_output.put_line(c||' is the greatest');
    end if;
else if(b>c) then
    dbms_output.put_line(b||' is the greatest');
end if;
end;
/