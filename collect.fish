#!/usr/bin/env fish

set -l ranges (seq 10)

rm -r inputs

for x in $ranges
    ./gen.py --num $x &
end
wait

set -gx TP2_MACHINE 1
set -g db "times.db"

function table -a name
    sqlite $db "create table if not exists $name(n int primary key, user int, system int, clock int);"
end

function insert -a name n user system clock
    sqlite $db "insert into $name ($n, $user, $system, $clock);"
end

table dyn
table alt

for x in $ranges
    echo Starting alt $x
    insert alt $x $(./tp2 A inputs/entrada-$x.txt | string join ' ')
    echo Starting dyn $x
    insert dyn $x $(./tp2 D inputs/entrada-$x.txt | string join ' ')
end
