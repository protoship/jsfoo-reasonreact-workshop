type t;

let make: (~title: string, ~startsAtOne: bool, ~steps: int) => t;

let id: t => RandomId.t;

let title: t => string;

let startsAtOne: t => bool;

let steps: t => int;

let answer: t => option(int);

let indexOfAnswer: t => option(int);

let setTitle: (t, string) => t;

let toggleStartsAtOne: t => t;

let setSteps: (t, int) => t;

let setAnswer: (t, int) => t;

let resetAnswer: t => t;

let toList: t => list(int);