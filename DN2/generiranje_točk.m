(* ::Package:: *)

gen[st_]:=Module[{tocke},
{x,y}={RandomReal[{-1.5,1.5},st],RandomReal[{-1.5,1.5},st]};
tocke=Transpose[{x,y}];
{krog,kvadrat,izven}={{},{},{}};
Module[{i},For[i=1,i<=st,i++,
Which[
tocke[[i,1]]^2+tocke[[i,2]]^2<=1,AppendTo[krog,tocke[[i]]],
And[tocke[[i,1]]>=-1,tocke[[i,1]]<=1, tocke[[i,2]]>=-1,tocke[[i,2]]<=1],AppendTo[kvadrat,tocke[[i]]],
True,AppendTo[izven,tocke[[i]]]
]
]
]
]
