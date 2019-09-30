type t;

let make: (~title: string) => t;

let id: t => RandomId.t;

let title: t => string;

let answer: t => string;

let setTitle: (t, string) => t;

let setAnswer: (t, string) => t;