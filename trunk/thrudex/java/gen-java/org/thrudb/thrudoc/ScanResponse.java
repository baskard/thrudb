/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
package org.thrudb.thrudoc;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;

import org.apache.thrift.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.protocol.*;

public class ScanResponse implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("ScanResponse");
  private static final TField ENTITIES_FIELD_DESC = new TField("entities", TType.LIST, (short)1);
  private static final TField SEED_FIELD_DESC = new TField("seed", TType.STRING, (short)2);

  public List<Entity> entities;
  public static final int ENTITIES = 1;
  public String seed;
  public static final int SEED = 2;

  private final Isset __isset = new Isset();
  private static final class Isset implements java.io.Serializable {
  }

  public static final Map<Integer, FieldMetaData> metaDataMap = Collections.unmodifiableMap(new HashMap<Integer, FieldMetaData>() {{
    put(ENTITIES, new FieldMetaData("entities", TFieldRequirementType.DEFAULT, 
        new ListMetaData(TType.LIST, 
            new StructMetaData(TType.STRUCT, Entity.class))));
    put(SEED, new FieldMetaData("seed", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
  }});

  static {
    FieldMetaData.addStructMetaDataMap(ScanResponse.class, metaDataMap);
  }

  public ScanResponse() {
  }

  public ScanResponse(
    List<Entity> entities,
    String seed)
  {
    this();
    this.entities = entities;
    this.seed = seed;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public ScanResponse(ScanResponse other) {
    if (other.isSetEntities()) {
      List<Entity> __this__entities = new ArrayList<Entity>();
      for (Entity other_element : other.entities) {
        __this__entities.add(new Entity(other_element));
      }
      this.entities = __this__entities;
    }
    if (other.isSetSeed()) {
      this.seed = other.seed;
    }
  }

  @Override
  public ScanResponse clone() {
    return new ScanResponse(this);
  }

  public int getEntitiesSize() {
    return (this.entities == null) ? 0 : this.entities.size();
  }

  public java.util.Iterator<Entity> getEntitiesIterator() {
    return (this.entities == null) ? null : this.entities.iterator();
  }

  public void addToEntities(Entity elem) {
    if (this.entities == null) {
      this.entities = new ArrayList<Entity>();
    }
    this.entities.add(elem);
  }

  public List<Entity> getEntities() {
    return this.entities;
  }

  public void setEntities(List<Entity> entities) {
    this.entities = entities;
  }

  public void unsetEntities() {
    this.entities = null;
  }

  // Returns true if field entities is set (has been asigned a value) and false otherwise
  public boolean isSetEntities() {
    return this.entities != null;
  }

  public void setEntitiesIsSet(boolean value) {
    if (!value) {
      this.entities = null;
    }
  }

  public String getSeed() {
    return this.seed;
  }

  public void setSeed(String seed) {
    this.seed = seed;
  }

  public void unsetSeed() {
    this.seed = null;
  }

  // Returns true if field seed is set (has been asigned a value) and false otherwise
  public boolean isSetSeed() {
    return this.seed != null;
  }

  public void setSeedIsSet(boolean value) {
    if (!value) {
      this.seed = null;
    }
  }

  public void setFieldValue(int fieldID, Object value) {
    switch (fieldID) {
    case ENTITIES:
      if (value == null) {
        unsetEntities();
      } else {
        setEntities((List<Entity>)value);
      }
      break;

    case SEED:
      if (value == null) {
        unsetSeed();
      } else {
        setSeed((String)value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case ENTITIES:
      return getEntities();

    case SEED:
      return getSeed();

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  // Returns true if field corresponding to fieldID is set (has been asigned a value) and false otherwise
  public boolean isSet(int fieldID) {
    switch (fieldID) {
    case ENTITIES:
      return isSetEntities();
    case SEED:
      return isSetSeed();
    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof ScanResponse)
      return this.equals((ScanResponse)that);
    return false;
  }

  public boolean equals(ScanResponse that) {
    if (that == null)
      return false;

    boolean this_present_entities = true && this.isSetEntities();
    boolean that_present_entities = true && that.isSetEntities();
    if (this_present_entities || that_present_entities) {
      if (!(this_present_entities && that_present_entities))
        return false;
      if (!this.entities.equals(that.entities))
        return false;
    }

    boolean this_present_seed = true && this.isSetSeed();
    boolean that_present_seed = true && that.isSetSeed();
    if (this_present_seed || that_present_seed) {
      if (!(this_present_seed && that_present_seed))
        return false;
      if (!this.seed.equals(that.seed))
        return false;
    }

    return true;
  }

  @Override
  public int hashCode() {
    return 0;
  }

  public void read(TProtocol iprot) throws TException {
    TField field;
    iprot.readStructBegin();
    while (true)
    {
      field = iprot.readFieldBegin();
      if (field.type == TType.STOP) { 
        break;
      }
      switch (field.id)
      {
        case ENTITIES:
          if (field.type == TType.LIST) {
            {
              TList _list0 = iprot.readListBegin();
              this.entities = new ArrayList<Entity>(_list0.size);
              for (int _i1 = 0; _i1 < _list0.size; ++_i1)
              {
                Entity _elem2;
                _elem2 = new Entity();
                _elem2.read(iprot);
                this.entities.add(_elem2);
              }
              iprot.readListEnd();
            }
          } else { 
            TProtocolUtil.skip(iprot, field.type);
          }
          break;
        case SEED:
          if (field.type == TType.STRING) {
            this.seed = iprot.readString();
          } else { 
            TProtocolUtil.skip(iprot, field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();


    // check for required fields of primitive type, which can't be checked in the validate method
    validate();
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.entities != null) {
      oprot.writeFieldBegin(ENTITIES_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.STRUCT, this.entities.size()));
        for (Entity _iter3 : this.entities)        {
          _iter3.write(oprot);
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.seed != null) {
      oprot.writeFieldBegin(SEED_FIELD_DESC);
      oprot.writeString(this.seed);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder("ScanResponse(");
    boolean first = true;

    sb.append("entities:");
    if (this.entities == null) {
      sb.append("null");
    } else {
      sb.append(this.entities);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("seed:");
    if (this.seed == null) {
      sb.append("null");
    } else {
      sb.append(this.seed);
    }
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
    // check that fields of type enum have valid values
  }

}

