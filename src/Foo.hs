module Foo where

-- import Data.Vector.Storable
import Foreign.Ptr
import Data.Word

foreign import ccall unsafe "tableSum"
  c_rowSum :: Ptr Word8 -> Ptr Word8 -> Word64 -> IO ()

-- use the c_rowSum however, I don't really care, the point is in the flags used to invoke CC.
realcode = undefined
