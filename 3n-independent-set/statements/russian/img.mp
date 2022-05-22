input TEX;
prologues := 3; % make it work with ps2pdf
outputtemplate := "graph%c.eps"; % better file names

u := 3cm;
w := 0.1cm;
x := 1;
a := u;
r := 2*u/3;
f := r/12;

beginfig(1)
    pair v[];
    v[0] := (0 * a, 0 * a);
    v[1] := (4 * a, 0 * a);
    v[2] := (2 * a, 2 * a);

    draw v[0]--v[1] withpen pencircle scaled w;
    draw v[1]--v[2] withpen pencircle scaled w;
    draw v[2]--v[0] withpen pencircle scaled w;

    for i = 0 upto 2:
        if i = 0:
            draw v[i] withpen pencircle scaled r withcolor white;
            draw fullcircle scaled r shifted v[i] withpen pencircle scaled (2 * w);
        fi;
    endfor;
    for i = 0 upto 2:
        if i <> 0:
            draw v[i] withpen pencircle scaled r withcolor white;
            draw fullcircle scaled r shifted v[i] withpen pencircle scaled w;
        fi;
    endfor;

    label.top(btex $1$ etex, (0,0)) scaled f shifted v[0] shifted(0, -r/2);
    label.top(btex $2$ etex, (0,0)) scaled f shifted v[1] shifted(0, -r/2);
    label.top(btex $3$ etex, (0,0)) scaled f shifted v[2] shifted(0, -r/2);
endfig;

beginfig(2)
    pair v[];
    v[0] := (0 * a, 0 * a);
    v[1] := (4 * a, 0 * a);
    v[2] := (4 * a, 4 * a);
    v[3] := (0 * a, 4 * a);
    v[4] := (6 * a, 0 * a);
    v[5] := (6 * a, 4 * a);

    draw v[0]--v[1] withpen pencircle scaled w;
    draw v[1]--v[2] withpen pencircle scaled w;
    draw v[2]--v[3] withpen pencircle scaled w;
    draw v[3]--v[0] withpen pencircle scaled w;
    draw v[0]--v[2] withpen pencircle scaled w;
    draw v[1]--v[3] withpen pencircle scaled w;

    for i = 0 upto 5:
        if (i = 0) or (i = 4):
            draw v[i] withpen pencircle scaled r withcolor white;
            draw fullcircle scaled r shifted v[i] withpen pencircle scaled (2 * w);
        fi;
    endfor;
    for i = 0 upto 5:
        if  (i <> 0) and (i <> 4):
            draw v[i] withpen pencircle scaled r withcolor white;
            draw fullcircle scaled r shifted v[i] withpen pencircle scaled w;
        fi;
    endfor;

    label.top(btex $1$ etex, (0,0)) scaled f shifted v[0] shifted(0, -r/2);
    label.top(btex $2$ etex, (0,0)) scaled f shifted v[1] shifted(0, -r/2);
    label.top(btex $3$ etex, (0,0)) scaled f shifted v[2] shifted(0, -r/2);
    label.top(btex $4$ etex, (0,0)) scaled f shifted v[3] shifted(0, -r/2);
    label.top(btex $5$ etex, (0,0)) scaled f shifted v[4] shifted(0, -r/2);
    label.top(btex $6$ etex, (0,0)) scaled f shifted v[5] shifted(0, -r/2);
endfig;

end.
