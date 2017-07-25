-- custom osc send to openFrameworks

module OSCSenderToOF where
import Sound.Tidal.Stream
import Sound.Tidal.Pattern
import Sound.Tidal.Parse
import Sound.Tidal.OscStream
import Sound.Tidal.Context

openFrameworks = Shape {
  -- Define the parameters. The first bit is the type - S for
  -- string, F for float, I for integer. The second part is the
  -- name of the parameter. The third is the default value for the
  -- parameter (only used if 'namedParams' defined below is set to
  -- 'False', so set to Nothing here).
  params = [
    S "text" Nothing
  ],
  -- Whether to add the current cycles per second to the message
  cpsStamp = False,
  -- How far ahead of time to send the message
  latency = 0.0
}

openFrameworksSlang = OscSlang {
  -- the OSC 'path'
  path = "/test",
  -- Whether to timestamp the message with
  -- its logical time - can be 'BundleStamp'
  -- (put in a timestamped bundle),
  -- 'MessageStamp' (put in the message
  -- parameters), or 'NoStamp' (don't timestamp)
  timestamp = NoStamp,
  -- Whether to interleave the parameter
  -- names in the message. If this isn't
  -- set, all parameters will be sent, using
  -- defaults set above if they're not
  -- given in a tidal pattern
  namedParams = True,
  -- Parameters to stick on the beginning of
  -- a message
  preamble = []
}

-- a function to start your OSC stream, where "127.0.0.1" is the
-- target host and 8000 the port number
openFrameworksStream = do
  s <- makeConnection "127.0.0.1" 8000 openFrameworksSlang
  stream (Backend s $ (\_ _ _ -> return ())) openFrameworks

-- pattern parameter functions, where makeS is for string, makeF for floats, and so on.
-- Many parameter functions are already defined and don't need re-defining, see here:
-- https://github.com/tidalcycles/Tidal/blob/master/Sound/Tidal/Params.hs
text = makeS openFrameworks "text"
