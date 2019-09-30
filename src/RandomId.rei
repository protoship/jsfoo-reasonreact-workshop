  type t;

  let generate: unit => t;

  let toString: t => string;

  let eq: (t, t) => bool;