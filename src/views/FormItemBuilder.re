let toBuilder = onUpdate =>
  FormItem.(
    fun
    | OpinionScale(opinionScale) =>
      <OpinionScaleBuilder
        opinionScale
        onChange={x => OpinionScale(x) |> onUpdate}
      />
    | ShortText(shortText) =>
      <ShortTextBuilder shortText onChange={x => ShortText(x) |> onUpdate} />
  );

[@react.component]
let make = (~formItem, ~onUpdate, ~onDelete) =>
  <div className="border-b border-dashed pb-6 mb-8">
    {formItem |> toBuilder(onUpdate)}
    <div
      className="flex justify-end text-gray-800 opacity-25 hover:opacity-100">
      <a
        className="text-sm leading-none flex items-center"
        href="#"
        onClick={formItem |> onDelete}>
        <img className="w-4 h-4 mr-1" src=Icon.trashAlt />
        <span> {React.string("Remove")} </span>
      </a>
    </div>
  </div>;