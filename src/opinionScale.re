open Belt;

type t = {
  id: RandomId.t,
  title: string,
  startsAtOne: bool,
  steps: int,
  answer: option(int),
};

let make = (~title, ~startsAtOne, ~steps) => {
  title,
  startsAtOne,
  steps,
  id: RandomId.generate(),
  answer: None,
};

let id = t => t.id;

let title = t => t.title;

let startsAtOne = t => t.startsAtOne;

let steps = t => t.steps;

let answer = t => t.answer;

let indexOfAnswer = t =>
  t.answer->Option.map(x => t |> startsAtOne ? x - 1 : x);

let setTitle = (t, title) => {...t, title};

let toggleStartsAtOne = t => {...t, startsAtOne: !t.startsAtOne};

let setSteps = (t, steps) => {...t, steps};

let setAnswer = (t, answer) => {
  ...t,
  answer: Some(answer) == t.answer ? None : Some(answer),
};
let resetAnswer = t => {...t, answer: None};

let toList = t => {
  let f = t.startsAtOne ? i => i + 1 : (i => i);
  t.steps->List.makeBy(f);
};