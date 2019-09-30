[@react.component]
let make = (~opinionScale, ~onChange) => {
  let onTitleChange = title =>
    title |> OpinionScale.setTitle(opinionScale) |> onChange;

  let onToggleStartsAtOne = () =>
    opinionScale
    |> OpinionScale.resetAnswer
    |> OpinionScale.toggleStartsAtOne
    |> onChange;

  let onStepsChange = steps =>
    steps
    |> OpinionScale.setSteps(opinionScale |> OpinionScale.resetAnswer)
    |> onChange;

  <>
    <label className="block mb-2">
      <input
        className="w-full outline-none bg-transparent text-2xl leading-loose"
        type_="text"
        placeholder="Type your question here..."
        size=50
        value={opinionScale |> OpinionScale.title}
        onChange={event =>
          event->ReactEvent.Form.target##value |> onTitleChange
        }
      />
    </label>
    <label className="flex items-center mb-2">
      <span className="mr-4 text-sm leading-none text-gray-700">
        {React.string("Steps")}
      </span>
      <input
        className="mr-1"
        type_="range"
        min=5
        max="11"
        value={opinionScale |> OpinionScale.steps |> string_of_int}
        onChange={event =>
          event->ReactEvent.Form.target##value |> onStepsChange
        }
      />
      <span className="text-sm leading-none text-gray-600">
        {opinionScale |> OpinionScale.steps |> string_of_int |> React.string}
      </span>
    </label>
    <label className="block mb-2">
      <span className="mr-2 text-sm leading-none  text-gray-700">
        {React.string("Start scale at 1")}
      </span>
      <input
        type_="checkbox"
        checked={opinionScale |> OpinionScale.startsAtOne}
        onChange={_ => onToggleStartsAtOne()}
      />
    </label>
  </>;
};