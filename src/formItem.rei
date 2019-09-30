type t =
  | OpinionScale(OpinionScale.t)
  | ShortText(ShortText.t);

let id: t => RandomId.t;

