type t = {
  id: RandomId.t,
  title: string,
  answer: string,
};

let make = (~title) => {title, id: RandomId.generate(), answer: ""};

let id = t => t.id;

let title = t => t.title;

let answer = t => t.answer;

let setTitle = (t, title) => {...t, title};

let setAnswer = (t, answer) => {...t, answer};