type t =
  | OpinionScale(OpinionScale.t)
  | ShortText(ShortText.t);

let id =
  fun
  | OpinionScale(x) => x |> OpinionScale.id
  | ShortText(x) => x |> ShortText.id;