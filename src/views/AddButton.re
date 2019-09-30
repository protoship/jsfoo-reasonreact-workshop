[@react.component]
let make = (~onClick, ~icon, ~text) =>
  <button onClick className="p-2 bg-white text-sm leading-none mr-4 rounded-sm w-40 opacity-75 hover:opacity-100">
    <img src=icon className="w-4 h-4 mr-2 inline align-middle" />
    {React.string(text)}
  </button>;