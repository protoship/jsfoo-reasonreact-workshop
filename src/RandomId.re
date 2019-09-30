type t = string;

[@bs.module "shortid"] external generate: unit => t = "generate";

let toString = t => t;

let eq = (t1, t2) => t1 == t2;