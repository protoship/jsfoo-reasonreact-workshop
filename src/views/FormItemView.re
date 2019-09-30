open Belt;

let toFormItemView = onUpdate =>
  FormItem.(
    fun
    | OpinionScale(opinionScale) =>
      <OpinionScaleView
        opinionScale
        onChange={x => OpinionScale(x) |> onUpdate}
      />
    | ShortText(shortText) =>
      <ShortTextView shortText onChange={x => ShortText(x) |> onUpdate} />
  );

[@react.component]
let make = (~formItems, ~onUpdate) => {
  let formItemViews =
    formItems->List.mapWithIndex((i, form) =>
      <div
        key={form |> FormItem.id |> RandomId.toString} className="py-4 mb-4">
        <p className="text-2xl font-thin mb-2 text-blue-400">
          {React.string(string_of_int(i + 1) ++ ".")}
        </p>
        {form |> toFormItemView(onUpdate)}
      </div>
    )
    |> List.toArray
    |> React.array;

  <form
    className="w-9/12 mx-auto p-3 py-6"
    onSubmit={event => event |> ReactEvent.Form.preventDefault}>
    <div className="mb-4"> formItemViews </div>
    <a
      href="#"
      className="mt-6 p-2 bg-red-500 hover:bg-red-700 text-white w-32 inline-block text-center font-semibold rounded-full"
      onClick={event => event |> ReactEvent.Mouse.preventDefault}>
      {React.string("Submit")}
    </a>
  </form>;
};