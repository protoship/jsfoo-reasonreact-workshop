[@react.component]
let make = () => {
  <div className="w-screen h-screen flex justify-center items-center">
    <div className="md:flex bg-purple-200 rounded-lg shadow-lg p-6">
      <img
        className="h-16 w-16 md:h-24 md:w-24 rounded-full mx-auto md:mx-0 md:mr-6"
        src=Image.avatar0
      />
      <div className="text-center md:text-left font-mono">
        <h2 className="text-lg"> {React.string("Erin Lindford")} </h2>
        <div className="text-purple-500">
          {React.string("Customer Support")}
        </div>
        <div className="text-gray-600">
          {React.string("erinlindford@example.com")}
        </div>
        <div className="text-gray-600">
          {React.string("(555) 765-4321")}
        </div>
      </div>
    </div>
  </div>;
};