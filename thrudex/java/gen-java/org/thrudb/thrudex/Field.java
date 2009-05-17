/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
package org.thrudb.thrudex;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import org.apache.thrift.TBase;
import org.apache.thrift.TException;
import org.apache.thrift.TFieldRequirementType;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;
import org.apache.thrift.protocol.TField;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.protocol.TProtocolException;
import org.apache.thrift.protocol.TProtocolUtil;
import org.apache.thrift.protocol.TStruct;
import org.apache.thrift.protocol.TType;

public class Field implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("Field");
  private static final TField KEY_FIELD_DESC = new TField("key", TType.STRING, (short)1);
  private static final TField VALUE_FIELD_DESC = new TField("value", TType.STRING, (short)2);
  private static final TField TYPE_FIELD_DESC = new TField("type", TType.I32, (short)3);
  private static final TField WEIGHT_FIELD_DESC = new TField("weight", TType.I32, (short)4);
  private static final TField SORTABLE_FIELD_DESC = new TField("sortable", TType.BOOL, (short)5);

  public String key;
  public static final int KEY = 1;
  public String value;
  public static final int VALUE = 2;
  public int type;
  public static final int TYPE = 3;
  public int weight;
  public static final int WEIGHT = 4;
  public boolean sortable;
  public static final int SORTABLE = 5;

  private final Isset __isset = new Isset();
  private static final class Isset implements java.io.Serializable {
    public boolean type = false;
    public boolean weight = false;
    public boolean sortable = false;
  }

  public static final Map<Integer, FieldMetaData> metaDataMap = Collections.unmodifiableMap(new HashMap<Integer, FieldMetaData>() {{
    put(KEY, new FieldMetaData("key", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    put(VALUE, new FieldMetaData("value", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.STRING)));
    put(TYPE, new FieldMetaData("type", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    put(WEIGHT, new FieldMetaData("weight", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.I32)));
    put(SORTABLE, new FieldMetaData("sortable", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.BOOL)));
  }});

  static {
    FieldMetaData.addStructMetaDataMap(Field.class, metaDataMap);
  }

  public Field() {
    this.type = 2;

    this.weight = 1;

    this.sortable = false;

  }

  public Field(
    String key,
    String value,
    int type,
    int weight,
    boolean sortable)
  {
    this();
    this.key = key;
    this.value = value;
    this.type = type;
    this.__isset.type = true;
    this.weight = weight;
    this.__isset.weight = true;
    this.sortable = sortable;
    this.__isset.sortable = true;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public Field(Field other) {
    if (other.isSetKey()) {
      this.key = other.key;
    }
    if (other.isSetValue()) {
      this.value = other.value;
    }
    __isset.type = other.__isset.type;
    this.type = other.type;
    __isset.weight = other.__isset.weight;
    this.weight = other.weight;
    __isset.sortable = other.__isset.sortable;
    this.sortable = other.sortable;
  }

  @Override
  public Field clone() {
    return new Field(this);
  }

  public String getKey() {
    return this.key;
  }

  public void setKey(String key) {
    this.key = key;
  }

  public void unsetKey() {
    this.key = null;
  }

  // Returns true if field key is set (has been asigned a value) and false otherwise
  public boolean isSetKey() {
    return this.key != null;
  }

  public void setKeyIsSet(boolean value) {
    if (!value) {
      this.key = null;
    }
  }

  public String getValue() {
    return this.value;
  }

  public void setValue(String value) {
    this.value = value;
  }

  public void unsetValue() {
    this.value = null;
  }

  // Returns true if field value is set (has been asigned a value) and false otherwise
  public boolean isSetValue() {
    return this.value != null;
  }

  public void setValueIsSet(boolean value) {
    if (!value) {
      this.value = null;
    }
  }

  public int getType() {
    return this.type;
  }

  public void setType(int type) {
    this.type = type;
    this.__isset.type = true;
  }

  public void unsetType() {
    this.__isset.type = false;
  }

  // Returns true if field type is set (has been asigned a value) and false otherwise
  public boolean isSetType() {
    return this.__isset.type;
  }

  public void setTypeIsSet(boolean value) {
    this.__isset.type = value;
  }

  public int getWeight() {
    return this.weight;
  }

  public void setWeight(int weight) {
    this.weight = weight;
    this.__isset.weight = true;
  }

  public void unsetWeight() {
    this.__isset.weight = false;
  }

  // Returns true if field weight is set (has been asigned a value) and false otherwise
  public boolean isSetWeight() {
    return this.__isset.weight;
  }

  public void setWeightIsSet(boolean value) {
    this.__isset.weight = value;
  }

  public boolean isSortable() {
    return this.sortable;
  }

  public void setSortable(boolean sortable) {
    this.sortable = sortable;
    this.__isset.sortable = true;
  }

  public void unsetSortable() {
    this.__isset.sortable = false;
  }

  // Returns true if field sortable is set (has been asigned a value) and false otherwise
  public boolean isSetSortable() {
    return this.__isset.sortable;
  }

  public void setSortableIsSet(boolean value) {
    this.__isset.sortable = value;
  }

  public void setFieldValue(int fieldID, Object value) {
    switch (fieldID) {
    case KEY:
      if (value == null) {
        unsetKey();
      } else {
        setKey((String)value);
      }
      break;

    case VALUE:
      if (value == null) {
        unsetValue();
      } else {
        setValue((String)value);
      }
      break;

    case TYPE:
      if (value == null) {
        unsetType();
      } else {
        setType((Integer)value);
      }
      break;

    case WEIGHT:
      if (value == null) {
        unsetWeight();
      } else {
        setWeight((Integer)value);
      }
      break;

    case SORTABLE:
      if (value == null) {
        unsetSortable();
      } else {
        setSortable((Boolean)value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case KEY:
      return getKey();

    case VALUE:
      return getValue();

    case TYPE:
      return getType();

    case WEIGHT:
      return new Integer(getWeight());

    case SORTABLE:
      return new Boolean(isSortable());

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  // Returns true if field corresponding to fieldID is set (has been asigned a value) and false otherwise
  public boolean isSet(int fieldID) {
    switch (fieldID) {
    case KEY:
      return isSetKey();
    case VALUE:
      return isSetValue();
    case TYPE:
      return isSetType();
    case WEIGHT:
      return isSetWeight();
    case SORTABLE:
      return isSetSortable();
    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object that) {
    if (that == null)
      return false;
    if (that instanceof Field)
      return this.equals((Field)that);
    return false;
  }

  public boolean equals(Field that) {
    if (that == null)
      return false;

    boolean this_present_key = true && this.isSetKey();
    boolean that_present_key = true && that.isSetKey();
    if (this_present_key || that_present_key) {
      if (!(this_present_key && that_present_key))
        return false;
      if (!this.key.equals(that.key))
        return false;
    }

    boolean this_present_value = true && this.isSetValue();
    boolean that_present_value = true && that.isSetValue();
    if (this_present_value || that_present_value) {
      if (!(this_present_value && that_present_value))
        return false;
      if (!this.value.equals(that.value))
        return false;
    }

    boolean this_present_type = true;
    boolean that_present_type = true;
    if (this_present_type || that_present_type) {
      if (!(this_present_type && that_present_type))
        return false;
      if (this.type != that.type)
        return false;
    }

    boolean this_present_weight = true;
    boolean that_present_weight = true;
    if (this_present_weight || that_present_weight) {
      if (!(this_present_weight && that_present_weight))
        return false;
      if (this.weight != that.weight)
        return false;
    }

    boolean this_present_sortable = true;
    boolean that_present_sortable = true;
    if (this_present_sortable || that_present_sortable) {
      if (!(this_present_sortable && that_present_sortable))
        return false;
      if (this.sortable != that.sortable)
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
        case KEY:
          if (field.type == TType.STRING) {
            this.key = iprot.readString();
          } else { 
            TProtocolUtil.skip(iprot, field.type);
          }
          break;
        case VALUE:
          if (field.type == TType.STRING) {
            this.value = iprot.readString();
          } else { 
            TProtocolUtil.skip(iprot, field.type);
          }
          break;
        case TYPE:
          if (field.type == TType.I32) {
            this.type = iprot.readI32();
            this.__isset.type = true;
          } else { 
            TProtocolUtil.skip(iprot, field.type);
          }
          break;
        case WEIGHT:
          if (field.type == TType.I32) {
            this.weight = iprot.readI32();
            this.__isset.weight = true;
          } else { 
            TProtocolUtil.skip(iprot, field.type);
          }
          break;
        case SORTABLE:
          if (field.type == TType.BOOL) {
            this.sortable = iprot.readBool();
            this.__isset.sortable = true;
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
    if (this.key != null) {
      oprot.writeFieldBegin(KEY_FIELD_DESC);
      oprot.writeString(this.key);
      oprot.writeFieldEnd();
    }
    if (this.value != null) {
      oprot.writeFieldBegin(VALUE_FIELD_DESC);
      oprot.writeString(this.value);
      oprot.writeFieldEnd();
    }
    oprot.writeFieldBegin(TYPE_FIELD_DESC);
    oprot.writeI32(this.type);
    oprot.writeFieldEnd();
    oprot.writeFieldBegin(WEIGHT_FIELD_DESC);
    oprot.writeI32(this.weight);
    oprot.writeFieldEnd();
    oprot.writeFieldBegin(SORTABLE_FIELD_DESC);
    oprot.writeBool(this.sortable);
    oprot.writeFieldEnd();
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder("Field(");
    boolean first = true;

    sb.append("key:");
    if (this.key == null) {
      sb.append("null");
    } else {
      sb.append(this.key);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("value:");
    if (this.value == null) {
      sb.append("null");
    } else {
      sb.append(this.value);
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("type:");
    String type_name = FieldType.VALUES_TO_NAMES.get(this.type);
    if (type_name != null) {
      sb.append(type_name);
      sb.append(" (");
    }
    sb.append(this.type);
    if (type_name != null) {
      sb.append(")");
    }
    first = false;
    if (!first) sb.append(", ");
    sb.append("weight:");
    sb.append(this.weight);
    first = false;
    if (!first) sb.append(", ");
    sb.append("sortable:");
    sb.append(this.sortable);
    first = false;
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
    // check that fields of type enum have valid values
    if (isSetType() && !FieldType.VALID_VALUES.contains(type)){
      throw new TProtocolException("The field 'type' has been assigned the invalid value " + type);
    }
  }

}

