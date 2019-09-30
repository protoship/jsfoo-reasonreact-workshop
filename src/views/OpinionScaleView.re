open Belt;

[@react.component]
let make = (~opinionScale, ~onChange) => {
  let length = opinionScale |> OpinionScale.toList |> List.length;

  let isLastItemIndex = i => i == length;

  let border = i => i |> isLastItemIndex ? "" : "border-r";

  let selected = i =>
    opinionScale |> OpinionScale.indexOfAnswer == Some(i)
      ? "bg-gray-600 text-white" : "bg-gray-200";

  let scaleItem = (i, scale) =>
    <a
      className={
        "font-thin p-3 text-2xl leading-normal "
        ++ border(i)
        ++ " "
        ++ selected(i)
      }
      key={scale |> string_of_int}
      href="#"
      onClick={event => {
        event |> ReactEvent.Mouse.preventDefault;
        scale |> OpinionScale.setAnswer(opinionScale) |> onChange;
      }}>
      {React.string(scale |> string_of_int)}
    </a>;

  let opinionScaleInput =
    <div>
      {scaleItem
       |> List.mapWithIndex(opinionScale |> OpinionScale.toList)
       |> List.toArray
       |> React.array}
    </div>;

  <>
    <p className="font-thin text-3xl leading-normal mb-4">
      {opinionScale |> OpinionScale.title |> React.string}
    </p>
    opinionScaleInput
  </>;
};